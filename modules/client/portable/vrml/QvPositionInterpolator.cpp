#include <QvPositionInterpolator.h>
#include <GxTypes.h>

QV_NODE_SOURCE(QvPositionInterpolator);

QvPositionInterpolator::QvPositionInterpolator()
{
    QV_NODE_CONSTRUCTOR(QvPositionInterpolator);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(value);
    QV_NODE_ADD_FIELD(values);
    QV_NODE_ADD_FIELD(fraction);
    //QV_NODE_ADD_FIELD_IN(fraction);
    QV_NODE_ADD_FIELD(keys);
    QV_NODE_SET_EVENT_IN(fraction);

}

QvPositionInterpolator::~QvPositionInterpolator()
{
}

bool QvPositionInterpolator::set_fraction(const void * vfrac)
{
	float frac = *(float*)vfrac;
	if(fraction != frac)
	{
		int ioldr1, ioldr2;	// rotation indices
		lookup(fraction.value, ioldr1, ioldr2);
		fraction.value = frac;
		//  Needs to adjust value, then signal routes that change has happened
		int ir1, ir2;	// rotation indices
		lookup(frac, ir1, ir2);
		//TRACE3("Interpolating : fraction = %g, frames %d and %d\n", frac, ir1, ir2);
		// Check for "remaining off the same end" cases - don't update since
		// nothing has changed
		if(ir1 == ioldr1 && ir1 == keys.num - 1) return TRUE;
		if(ir2 == ioldr2 && ir2 == 0) return TRUE;
		if(ir2 >= values.num) return FALSE;		// illegal - actually, counts must match
												// but we'll be more generous and allow
												// anything except referencing a non-existent
												// frame

		if(ir1 == ir2 || keys.values[ir1] == keys.values[ir2])
		{
			// trivial case
			value.setValue(&values.values[ir1]);
		}
		else
		{
			float u = (frac - keys.values[ir1]) / (keys.values[ir2] - keys.values[ir1]);
			GxVec3f v(*((GxVec3f*)(values.values + ir1 * 3)));
			GxVec3f v2(*((GxVec3f*)(values.values + ir2 * 3)));

			v *= 1 - u;
			v2 *= u;
			v += v2;
			value.setValue(&v);			// wants float[3]
		}
	}
	return true;
}
