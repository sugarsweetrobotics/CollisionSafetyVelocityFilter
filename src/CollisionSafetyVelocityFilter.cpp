// -*- C++ -*-
/*!
 * @file  CollisionSafetyVelocityFilter.cpp
 * @brief Collision Avoider using Range Sensor for Mobile Robots
 * @date $Date$
 *
 * $Id$
 */

#include "CollisionSafetyVelocityFilter.h"

// Module specification
// <rtc-template block="module_spec">
static const char* collisionsafetyvelocityfilter_spec[] =
  {
    "implementation_id", "CollisionSafetyVelocityFilter",
    "type_name",         "CollisionSafetyVelocityFilter",
    "description",       "Collision Avoider using Range Sensor for Mobile Robots",
    "version",           "1.0.0",
    "vendor",            "SugarSweetRobotics",
    "category",          "Navigation",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.deadRangeAngleRadian", "0.78",
    "conf.default.maxRangeAngleRadian", "1.57",
    "conf.default.deadDistanceMeter", "0.1",
    "conf.default.maxDistanceMeter", "1.0",
    "conf.default.distanceToForce", "1.0",
    "conf.default.FxToVx", "0.01",
    "conf.default.FxToVy", "0.0",
    "conf.default.FxToVa", "0.0",
    "conf.default.FyToVx", "0.0",
    "conf.default.FyToVy", "0.1",
    "conf.default.FyToVa", "0.1",
	"conf.default.skipCount", "10",
	"conf.default.G1", "1.0",
	"conf.default.G2", "0.0",
	"conf.default.minVelocity", "0.05",
    "conf.default.debug", "0",
	
    // Widget
    "conf.__widget__.deadRangeAngleRadian", "text",
    "conf.__widget__.maxRangeAngleRadian", "text",
    "conf.__widget__.deadDistanceMeter", "text",
    "conf.__widget__.maxDistanceMeter", "text",
    "conf.__widget__.distanceToForce", "text",
    "conf.__widget__.FxToVx", "text",
    "conf.__widget__.FxToVy", "text",
    "conf.__widget__.FxToVa", "text",
    "conf.__widget__.FyToVx", "text",
    "conf.__widget__.FyToVy", "text",
    "conf.__widget__.FyToVa", "text",
    "conf.__widget__.debug", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
CollisionSafetyVelocityFilter::CollisionSafetyVelocityFilter(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_rangeIn("range", m_range),
    m_VinIn("Vin", m_Vin),
    m_VoutOut("Vout", m_Vout)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
CollisionSafetyVelocityFilter::~CollisionSafetyVelocityFilter()
{
}



RTC::ReturnCode_t CollisionSafetyVelocityFilter::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("range", m_rangeIn);
  addInPort("Vin", m_VinIn);

  // Add Data Listener. DataListener class is defined in CollisionSafetyVelocityFilter.h
  m_VinIn.addConnectorDataListener(ON_BUFFER_WRITE, new DataListener(this));
  
  // Set OutPort buffer
  addOutPort("Vout", m_VoutOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("deadRangeAngleRadian", m_deadRangeAngleRadian, "0.78");
  bindParameter("maxRangeAngleRadian", m_maxRangeAngleRadian, "1.57");
  bindParameter("deadDistanceMeter", m_deadDistanceMeter, "0.1");
  bindParameter("maxDistanceMeter", m_maxDistanceMeter, "1.0");
  bindParameter("distanceToForce", m_distanceToForce, "1.0");
  bindParameter("FxToVx", m_FxToVx, "0.01");
  bindParameter("FxToVy", m_FxToVy, "0.0");
  bindParameter("FxToVa", m_FxToVa, "0.0");
  bindParameter("FyToVx", m_FyToVx, "0.0");
  bindParameter("FyToVy", m_FyToVy, "0.1");
  bindParameter("FyToVa", m_FyToVa, "0.1");
  bindParameter("skipCount", m_skipCount, "10");
  bindParameter("G1", m_G1, "1.0");
  bindParameter("G2", m_G2, "0.0");
  bindParameter("minVelocity", m_minVelocity, "0.05");
  bindParameter("debug", m_debug, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t CollisionSafetyVelocityFilter::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CollisionSafetyVelocityFilter::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CollisionSafetyVelocityFilter::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t CollisionSafetyVelocityFilter::onActivated(RTC::UniqueId ec_id)
{
	m_rangeInit = false;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t CollisionSafetyVelocityFilter::onDeactivated(RTC::UniqueId ec_id)
{
	m_rangeInit = false;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t CollisionSafetyVelocityFilter::onExecute(RTC::UniqueId ec_id)
{
	if (m_rangeIn.isNew()) {
		m_rangeInit = true;
		m_rangeIn.read();
	}
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t CollisionSafetyVelocityFilter::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CollisionSafetyVelocityFilter::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CollisionSafetyVelocityFilter::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CollisionSafetyVelocityFilter::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CollisionSafetyVelocityFilter::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void CollisionSafetyVelocityFilterInit(RTC::Manager* manager)
  {
    coil::Properties profile(collisionsafetyvelocityfilter_spec);
    manager->registerFactory(profile,
                             RTC::Create<CollisionSafetyVelocityFilter>,
                             RTC::Delete<CollisionSafetyVelocityFilter>);
  }
  
};


