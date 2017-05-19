#include <QvSensor.h>

QV_NODE_SOURCE(QvSensor);

QvSensor::QvSensor()
{
    QV_NODE_CONSTRUCTOR(QvSensor);
    isBuiltIn = TRUE;
#if 0
    QV_NODE_ADD_FIELD(m_xxx);

	m_xxx.value = 0;
#endif
}

QvSensor::~QvSensor()
{
}

#if 0
#endif
