/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#include <ecal/ecalc.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  // the client handle
  ECAL_HANDLE clt = 0;

  // initialize eCAL API
  eCAL_Initialize(argc, argv, "service_client_c", eCAL_Init_Default);

  // create client for "service1"
  clt = eCAL_Client_Create("service1");

  // call service method
  while (eCAL_Ok())
  {
    struct SServiceInfoC service_info;
    char                 request[]                 = "HELLO";
    char                 response[sizeof(request)] = { 0 };
    // call method "echo"
    printf("Calling service1:echo ..\n");
    if (eCAL_Client_Call_Wait(clt, "", "echo", request, sizeof(request), &service_info, &response, sizeof(response)))
    {
      // process response
      switch (service_info.call_state)
      {
      case call_state_executed:
        printf("Method 'echo' executed. Response : ");
        printf("%s", response);
        printf("\n\n");
        break;
      case call_state_failed:
        printf("Method 'echo' failed. Error : ");
        printf("%s", service_info.error_msg);
        printf("\n\n");
        break;
      default:
        break;
      }
    }
    else
    {
      printf("Service / method not found :-(\n\n");
    }
    // sleep 100 ms
    eCAL_Process_SleepMS(100);
  }

  // destroy client for "service1"
  eCAL_Client_Destroy(clt);

  // finalize eCAL API
  eCAL_Finalize(eCAL_Init_All);

  return(0);
}
