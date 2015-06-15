#include "unity.h"
#include "stm32f4xx_hal_gpio.h"
#include "mock_Timer.h"
#include "mock_LED.h"
#include "mock_Button.h"
#include "Message.h"
#include "LedSM.h"






void setUp(void)

{

}



void tearDown(void)

{

}



void test_LedSM_should_change_state_to_LED_BLINKING_ON_when_receive_message_CHANGE_MODE___INITIAL_LED_OFF()

{

 LedData ledData ;

 ledInitData(&ledData);



 msg = DO_NOTHING ;



 turnOffLED_CMockExpect(25, LED3);

 ledSM(&ledData);

 UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_OFF)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);



  msg = CHANGE_MODE;



 turnOffLED_CMockExpect(31, LED3);

 ledSM(&ledData);

 UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_BLINKING_ON)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);

}



void test_LedSM_should_change_state_to_LED_BLINKING_OFF_and_reset_timer_when_timer_expires___INITIAL_LED_BLINKING_ON()

{

 LedData ledData ;

 ledData.state = LED_BLINKING_ON ;



 msg = DO_NOTHING ;



 turnOnLED_CMockExpect(43, LED3);

 checkTime_CMockExpectAndReturn(44, 500, LED3, 0);

 ledSM(&ledData);

 UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_BLINKING_ON)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);



 turnOnLED_CMockExpect(48, LED3);

 checkTime_CMockExpectAndReturn(49, 500, LED3, 1);

 ledSM(&ledData);

 UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_BLINKING_OFF)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);



}



void test_LedSM_should_change_state_to_LED_BLINKING_ON_and_reset_timer_when_timer_expires___INITIAL_LED_BLINKING_OFF()

{

 LedData ledData ;

 ledData.state = LED_BLINKING_OFF ;



 msg = DO_NOTHING ;



 turnOffLED_CMockExpect(62, LED3);

 checkTime_CMockExpectAndReturn(63, 500, LED3, 0);

 ledSM(&ledData);

 UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_BLINKING_OFF)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);



 turnOffLED_CMockExpect(67, LED3);

 checkTime_CMockExpectAndReturn(68, 500, LED3, 1);

 ledSM(&ledData);

 UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_BLINKING_ON)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);



}



void test_LEDSM_should_change_state_to_LED_ON_when_receive_message_CHANGE_MODE___INITIAL_LED_BLINKING_ON()

{

 LedData ledData ;

 ledData.state = LED_BLINKING_ON ;



 msg = CHANGE_MODE;



 turnOnLED_CMockExpect(81, LED3);

 ledSM(&ledData);

 UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_ON)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

}



void test_LEDSM_should_change_state_to_LED_ON_when_receive_message_CHANGE_MODE___INITIAL_LED_BLINKING_OFF()

{

 LedData ledData ;

 ledData.state = LED_BLINKING_OFF ;



 msg = CHANGE_MODE;



 turnOffLED_CMockExpect(93, LED3);

 ledSM(&ledData);

 UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_ON)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

}



void test_LEDSM_should_change_state_to_LED_OFF_when_receive_message_CHANGE_MODE__INITIAL_LED_ON()

{

 LedData ledData ;

 ledData.state = LED_ON ;



 msg = CHANGE_MODE;

 turnOnLED_CMockExpect(104, LED3);

 ledSM(&ledData);

 UnityAssertEqualNumber((_U_SINT)((ledData.state)), (_U_SINT)((LED_OFF)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

}
