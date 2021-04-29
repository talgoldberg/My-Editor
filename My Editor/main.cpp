
#include "Editor.h"

using namespace std;
int main(int argc, char* argv[])
{

   switch (argc)
   {
        case 1:{
            Editor editor1;
            editor1.loop();
        }break;

        case 2:{
            Editor editor2(argv[1]);
            editor2.loop();
        }break;
       
   }
   
    
   
    
    return 0;
}