#include <QvTimeSensor.h>
#ifdef HUGE
#undef HUGE
#endif

#include <math.h>

QV_NODE_SOURCE(QvTimeSensor);

QvTimeSensor::QvTimeSensor()
{
    QV_NODE_CONSTRUCTOR(QvTimeSensor);
    isBuiltIn = TRUE;

    QV_NODE_ADD_EXPOSED_FIELD(cycleInterval);
    QV_NODE_ADD_EXPOSED_FIELD(enabled);
    QV_NODE_ADD_EXPOSED_FIELD(loop);
    QV_NODE_ADD_EXPOSED_FIELD(startTime);
    QV_NODE_ADD_EXPOSED_FIELD(stopTime);

	// Need special set handler for each eventIn - all have logic associated
    QV_NODE_SET_EVENT_IN(cycleInterval);
    QV_NODE_SET_EVENT_IN(enabled);
    QV_NODE_SET_EVENT_IN(loop);
    QV_NODE_SET_EVENT_IN(startTime);
    QV_NODE_SET_EVENT_IN(stopTime);

	// We need to add these for routing purposes
	// Need to do new QV_NODE_EVENTOUT macros for non-readable
	// eventouts
    QV_NODE_EVENTOUT(cycleTime);
    QV_NODE_EVENTOUT(fraction);
    QV_NODE_EVENTOUT(time);
    QV_NODE_EVENTOUT(isActive);	  // no _changed on name!

	cycleInterval.value = 1;
	enabled.value       = TRUE;
	loop.value          = FALSE;
	startTime.value     = 0;
	stopTime.value      = 0;

	fraction.value = -1.;	  // illegal value, to guarantee first update
	boolFinal = FALSE;
	time.value = -1;
	isActive.value = FALSE;
}

QvTimeSensor::~QvTimeSensor()
{
}

void QvTimeSensor::Tick(double t)
{
	const double EPSILON = 1e-8;
 	if(cycleInterval <= 0) cycleInterval.value = 1;	// defeat bogus values now!

	if(enabled.value == FALSE)
	{
		time.value = t;	// need in case of enabling/disabling
		return;
	}
	if(t < startTime) return;

	QvBool boolForce = FALSE;

	double t1 = t;		// time to use for frac
	if(stopTime >= startTime && t >= stopTime)
	{
		if(boolFinal) return;
		t1 = stopTime;
		boolFinal = TRUE;
		boolForce = TRUE;
	}
	
	if(!loop.value && t1 >= startTime + cycleInterval)
	{
		if(boolFinal) return;
	}

	// We are active if we got here

	if(!isActive.value)
	{
		QvBool yup = TRUE;
		isActive.setValue(&yup);
	}

	double frac;

	if(!loop.value && t1 >= startTime + cycleInterval)
	{
		//if(boolFinal) return;		  // already checked!
		t1 = startTime + cycleInterval;
		boolFinal = TRUE;
		boolForce = TRUE;
		frac = 1;					// pegged at one forever
		cycleTime.setValue(&t1);	// need to do this just once
	}
	else
	{
		frac =  fmod(t1 - startTime, cycleInterval) / cycleInterval;
	}



	if(boolForce || fabs(frac - fraction) > EPSILON) 
	{
		if(frac < fraction)
		{
			// looping : output cycle changed
			cycleTime.setValue(&t1);
		}
		// value changed so push it out	
		float f = float(frac);
		fraction.setValue(&f);
	}

	if(boolForce || fabs(t - time) < EPSILON) 
	{	
		time.setValue(&t);
	}

	if(boolFinal)
	{
		QvBool nope = FALSE;
		isActive.setValue(&nope);
	}

	// NEED TO HANDLE ALL THE OTHER CASES AND OUTPUTS!!!?????? NOT DONE!!
}

QvBool QvTimeSensor::set_cycleInterval(const void * pval)
{
	double t = *(double*)pval;
	if(t <= 0) t = 1;	// defeat bogus values now!
	cycleInterval.value = t;
	boolFinal = FALSE;
	return true;
}

QvBool QvTimeSensor::set_enabled(const void * pval)
{
	QvBool val = *(QvBool*)pval;
	if(enabled.value != val)
	{
		enabled.value = val;
		if(!val)
		{
			double frac =  fmod(time - startTime, cycleInterval) / cycleInterval;
			double t1 = time;

			if(frac < fraction)
			{
				// output cycle changed
				cycleTime.setValue(&t1);
			}
			// value changed so push it out	
			float f = float(frac);
			fraction.setValue(&f);

			time.setValue(&t1);

			QvBool nope = FALSE;
			isActive.setValue(&nope);
		}
		else
		{
			boolFinal = FALSE;
		}
	}
	return true;
}

QvBool QvTimeSensor::set_loop(const void * pval)
{
	QvBool val = *(QvBool*)pval;
	if(isActive.value) return true;
	loop.value = val;
	return true;
}

QvBool QvTimeSensor::set_startTime(const void * pval)
{
	double t = *(double*)pval;
	if(isActive.value) return true;
	boolFinal = FALSE;
	startTime.value = t;
	return true;
}

QvBool QvTimeSensor::set_stopTime(const void * pval)
{
	// Not handling all the nastimesses here
	double t = *(double*)pval;
	stopTime.value = t;
	boolFinal = FALSE;
	return true;
}

