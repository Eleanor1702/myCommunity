#include "lib/exporter.h"

Exporter* Exporter::instance = NULL;

Exporter::Exporter(CommunityData* data){
    this->data = data;
}

void Exporter::exportShopinglist(){
    std::vector<std::string> list = data->getAllItemsString();
    exportFile.open("shopinglist.csv");
    exportFile << "Einkaufsliste";
    exportFile << "Anzahl, Produktname \n";


    for(std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++)    {
    //   std::cout<< it ;
     }
    exportFile.close();
}

void Exporter::exportCleaningplan(){
    exportFile.open("cleaningplan.csv");
    exportFile << "Putzplan \n" ;




    exportFile.close();

}

void Exporter::exportCalendar(){
    exportFile.open("calendar.csv");
    exportFile << "Kalender \n";
    exportFile <<"Datum, Beschreibung, Gemeinschaftlich";






    exportFile.close();

}

Exporter* Exporter::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new Exporter(data);
    }
    return instance;
}
