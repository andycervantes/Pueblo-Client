#ifndef  _QV_TIMESENSOR_
#define  _QV_TIMESENSOR_

#include <QvSubNode.h>
#include <QvSFFloat.h>
#include <QvSFTime.h>
#include <QvSFBool.h>
#include <QvSensor.h>

class QvTimeSensor : public QvSensor {

		QV_NODE_HEADER(QvTimeSensor);

	public:

		void Tick(double t);

	protected:
		// All are exposed
		QvSFTime   cycleInterval;
		QvSFBool   enabled;
		QvSFBool   loop;
		QvSFTime   startTime;
		QvSFTime   stopTime;

		// Current time - eventout  time_changed
		QvSFTime   time;
		// Current fraction - eventout  fraction_changed
		QvSFFloat  fraction;
		// Current cycleTime - eventout  cycleTime_changed
		QvSFFloat  cycleTime;

		QvSFBool	isActive;

		QvBool 		boolFinal;	// set when final for cycle is sent

		QvBool set_cycleInterval(const void * pval);
		QvBool set_enabled(const void * pval);
		QvBool set_loop(const void * pval);
		QvBool set_startTime(const void * pval);
		QvBool set_stopTime(const void * pval);

	protected:

};

#endif /* _QV_TIMESENSOR_ */
