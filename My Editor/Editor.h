
#include "Document.h"

using namespace std;

class Editor{

    private:

        Document* doc;

    public:
        
        Editor(){doc=new Document();}
        Editor(string s){doc=new Document(s);}
        void loop();
};