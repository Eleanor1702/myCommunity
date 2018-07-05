#include "Database/lib/exporter.h"

Exporter* Exporter::instance = NULL;

Exporter::Exporter(CommunityData* data){
    this->data = data;
}

void Exporter::exportShopinglist(){
    std::vector<std::string> list = data->getAllItemsString();
    const char* home;
    const char* unix_os = std::getenv("HOME");
    if(unix_os == NULL){
        home = std::getenv("USERPROFILE");
    }else{
        home = unix_os;
    }

    std::string path = std::string(home) + "/Desktop/shoppinglist.csv";
    exportFile.open(path);
    exportFile << "Einkaufsliste\n\n";
    exportFile << "Anzahl, Produktname \n";


    for(unsigned int i = 0; i != list.size(); i++)    {
       exportFile << list[i] ;
     }
    exportFile.close();
}

void Exporter::exportCleaningplan(int week){
    std::vector<std::string> list = data->getAllConcreteTasksString(week);
    const char* home;
    const char* unix_os = std::getenv("HOME");
    if(unix_os == NULL){
        home = std::getenv("USERPROFILE");
    }else{
        home = unix_os;
    }

    std::string path = std::string(home) + "/Desktop/cleaningplan.csv";
    exportFile.open(path);
    exportFile << "Putzplan \n" ;
    exportFile << "Taskname, Bewohner, Kalenderwoche\n\n";
    for(unsigned int i = 0; i != list.size(); i++){
        exportFile << list[i] ;
    }

    exportFile.close();
}

Exporter* Exporter::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new Exporter(data);
    }
    return instance;
}

Exporter::~Exporter(){
    instance = NULL;
}
