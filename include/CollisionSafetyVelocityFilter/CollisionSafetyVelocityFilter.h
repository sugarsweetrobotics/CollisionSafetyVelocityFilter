// -*- C++ -*-
/*!
 * @file  CollisionSafetyVelocityFilter.h
 * @brief Collision Avoider using Range Sensor for Mobile Robots
 * @date  $Date$
 *
 * $Id$
 */

#ifndef COLLISIONSAFETYVELOCITYFILTER_H
#define COLLISIONSAFETYVELOCITYFILTER_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
// </rtc-template>

using namespace RTC;

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

/*!
 * @class CollisionSafetyVelocityFilter
 * @brief Collision Avoider using Range Sensor for Mobile Robots
 *
 */
class CollisionSafetyVelocityFilter
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  CollisionSafetyVelocityFilter(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~CollisionSafetyVelocityFilter();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  deadRangeAngleRadian
   * - DefaultValue: 0.78
   */
  float m_deadRangeAngleRadian;
  /*!
   * 
   * - Name:  maxRangeAngleRadian
   * - DefaultValue: 1.57
   */
  float m_maxRangeAngleRadian;
  /*!
   * 
   * - Name:  deadDistanceMeter
   * - DefaultValue: 0.1
   */
  float m_deadDistanceMeter;
  /*!
   * 
   * - Name:  maxDistanceMeter
   * - DefaultValue: 1.0
   */
  float m_maxDistanceMeter;
  /*!
   * 
   * - Name:  distanceToForce
   * - DefaultValue: 1.0
   */
  float m_distanceToForce;
  /*!
   * 
   * - Name:  FxToVx
   * - DefaultValue: 0.01
   */
  float m_FxToVx;
  /*!
   * 
   * - Name:  FxToVy
   * - DefaultValue: 0.0
   */
  float m_FxToVy;
  /*!
   * 
   * - Name:  FxToVa
   * - DefaultValue: 0.0
   */
  float m_FxToVa;
  /*!
   * 
   * - Name:  FyToVx
   * - DefaultValue: 0.0
   */
  float m_FyToVx;
  /*!
   * 
   * - Name:  FyToVy
   * - DefaultValue: 0.1
   */
  float m_FyToVy;
  /*!
   * 
   * - Name:  FyToVa
   * - DefaultValue: 0.1
   */
  float m_FyToVa;

  float m_skipCount;

  float m_G1;

  float m_G2;

  float m_minVelocity;
  /*!
   * 
   * - Name:  debug
   * - DefaultValue: 0
   */
  int m_debug;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::RangeData m_range;
  /*!
   */
  InPort<RTC::RangeData> m_rangeIn;
  RTC::TimedVelocity2D m_Vin;
  /*!
   */
  InPort<RTC::TimedVelocity2D> m_VinIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedVelocity2D m_Vout;
  /*!
   */
  OutPort<RTC::TimedVelocity2D> m_VoutOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

 public:

	 bool m_rangeInit;
	 void calculateVelocity(const RTC::TimedVelocity2D& data) {
		 if (!m_rangeInit) {
			 std::cout << "[CollisionSafetyVelocityFilter] Range Data is not arrived. No velocity is output." << std::endl;
		 }


		 double Fx_sum = 0;
		 double Fy_sum = 0;
		 int step = m_skipCount;
		 int i;
		 for (i = 0; i < m_range.ranges.length(); i += step) {

			 double angle = m_range.config.minAngle + m_range.config.angularRes * i;
			 if (angle < -m_maxRangeAngleRadian || angle > +m_maxRangeAngleRadian) {
				 continue;
			 }

			 if (angle < m_deadRangeAngleRadian && angle > -m_deadRangeAngleRadian) {
				 continue;
			 }


		

			 double distance = m_range.ranges[i];
			 if (distance < m_deadDistanceMeter || distance > m_maxDistanceMeter) {
				 continue;
			 }


			 double factor = 1.57 - angle;
			 if (angle < 0) {
				 factor = -1.57 - angle;
			 }


			 double deltaDistance = m_maxDistanceMeter - distance;
			 /// ‹——£‚É‘Î‚·‚éƒQƒCƒ“G1, ‹——£‚Ì“ñæ‚É‘Î‚·‚éƒQƒCƒ“G2
			 double F = m_G1 * deltaDistance + m_G2 * (deltaDistance * deltaDistance);
			 double Fx = F * cos(angle);
			 double Fy = F * sin(angle);

			 Fx_sum += Fx;
			 Fy_sum += Fy;
		 }

		 double Fx_mean = Fx_sum / i;
		 double Fy_mean = Fy_sum / i;

		 //std::cout << "VY = " << vy << "\n";
		 m_Vout.data = m_Vin.data;
		 if (m_Vout.data.vx > m_minVelocity || m_Vout.data.vx < -m_minVelocity) {
			 m_Vout.data.vx = m_Vout.data.vx + m_FxToVx * Fx_mean + m_FyToVx * Fy_mean;
			 if (m_Vin.data.vx > 0) {
				 if (m_Vout.data.vx < m_minVelocity) {
					 m_Vout.data.vx = m_minVelocity;
				 }
			 }
			 else {
				 if (m_Vout.data.vx > -m_minVelocity) {
					 m_Vout.data.vx = -m_minVelocity;
				 }
			 }

			 m_Vout.data.vy = m_Vout.data.vy + m_FxToVy * Fx_mean + m_FyToVy * Fy_mean;
			 if (m_Vin.data.vy > 0) {
				 if (m_Vout.data.vy < m_minVelocity) {
					 m_Vout.data.vy = m_minVelocity;
				 }
			 }
			 else {
				 if (m_Vout.data.vy > -m_minVelocity) {
					 m_Vout.data.vy = -m_minVelocity;
				 }
			 }

			 m_Vout.data.va = m_Vout.data.va + m_FxToVa * Fx_mean + m_FyToVa * Fy_mean;
		 }
		 m_Vout.tm = m_Vin.tm;
		 m_VoutOut.write();
	 }
};




class DataListener
	: public ConnectorDataListenerT<RTC::TimedVelocity2D>
{
public:
	DataListener(CollisionSafetyVelocityFilter* rtc) : m_parent(rtc), vx(0), vy(0), vz(0) {}
	virtual ~DataListener()
	{
		//std::cout << "dtor of " << m_name << std::endl;
	}

	virtual void operator()(const ConnectorInfo& info,
		const RTC::TimedVelocity2D& data)
	{
		m_parent->calculateVelocity(data);
	};


	CollisionSafetyVelocityFilter *m_parent;
	double vx, vy, vz;
};


extern "C"
{
  DLL_EXPORT void CollisionSafetyVelocityFilterInit(RTC::Manager* manager);
};

#endif // COLLISIONSAFETYVELOCITYFILTER_H
