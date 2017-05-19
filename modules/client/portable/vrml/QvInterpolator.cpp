#include <QvInterpolator.h>

QV_NODE_SOURCE(QvInterpolator);

QvInterpolator::QvInterpolator()
{
    QV_NODE_CONSTRUCTOR(QvInterpolator);
    isBuiltIn = TRUE;

    //QV_NODE_ADD_FIELD(fraction);
    //QV_NODE_ADD_FIELD(keys);

	fraction.value = 0;

}

QvInterpolator::~QvInterpolator()
{
}

bool QvInterpolator::set_fraction(float frac)
{
	fraction.value = frac;
	return true;
}

bool QvInterpolator::lookup(float frac, int &low, int &high)
{
	// Linear search - oughta be binary
	low = 0;
	high = 0;

	if(frac < keys.values[low]) return true;		// off low end
	if(frac > keys.values[keys.num - 1])
	{
		low = high = keys.num - 1;
		return true;		// off high end
	}

	while(frac > keys.values[high] && high < keys.num) high ++;

	if(high > 0)
	{
		low = high - 1;
	}

	return true;
}
