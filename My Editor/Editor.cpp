
#include "Editor.h"
using namespace std;


void Editor::loop(){
    

    if(doc->file.empty())
        doc->editor_for_empty_file();
    if(!doc->file.empty())
        doc->editor();
}