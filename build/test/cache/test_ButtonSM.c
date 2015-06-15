#include "unity.h"
#include "mock_Timer.h"
#include "mock_LED.h"
#include "mock_Button.h"
#include "Message.h"
#include "ButtonSM.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_ButtonSM_should_change_state_to_PRESS__and_change_msg_when_button_is_pressed_INITIAL_RELEASE()

{

 ButtonData buttonData ;

 buttonInitData(&buttonData);



 UnityAssertEqualNumber((_U_SINT)((buttonData.state)), (_U_SINT)((RELEASE)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);



 isButtonPressed_CMockExpectAndReturn(24, 1);

 buttonSM(&buttonData);



 UnityAssertEqualNumber((_U_SINT)((buttonData.state)), (_U_SINT)((PRESS)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((msg)), (_U_SINT)((CHANGE_MODE)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

}



void test_ButtonSM_should_remain_at_state_RELEASE_when_button_is_released_INITIAL_RELEASE()

{

 ButtonData buttonData ;

 buttonInitData(&buttonData);



 UnityAssertEqualNumber((_U_SINT)((buttonData.state)), (_U_SINT)((RELEASE)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);



 isButtonPressed_CMockExpectAndReturn(38, 0);

 buttonSM(&buttonData);



 UnityAssertEqualNumber((_U_SINT)((buttonData.state)), (_U_SINT)((RELEASE)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

}



void test_ButtonSM_should_change_state_to_RELEASE_when_button_is_released_INITIAL_PRESS()

{

 ButtonData buttonData ;



 buttonData.state =PRESS ;



 UnityAssertEqualNumber((_U_SINT)((buttonData.state)), (_U_SINT)((PRESS)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);



 isButtonPressed_CMockExpectAndReturn(52, 0);

 buttonSM(&buttonData);



 UnityAssertEqualNumber((_U_SINT)((buttonData.state)), (_U_SINT)((RELEASE)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

}
