#include "parsinggraph.h"


TParsing::TParsing(QWidget* parent) : QWidget(parent) {
    short response = 0;
    while(response != 1 && response != -1){
        string path = getPath();
        graph = new Graph();
        response = parsingFile(path);
        if(response != 1){
            error(response);
        }
    }
}



string TParsing::getPath() {
    QFile* openFile = new QFile(QFileDialog::getOpenFileName(nullptr, tr("Open input file"), "../../practical8", tr("Text (*.txt)")));

    return openFile->fileName().toStdString();
}



short TParsing::parsingFile(const string& path){
    ifstream iFile(path);
    if(!iFile.is_open()){
        return -1;
    }
    string line;

    getline(iFile, line);

    string title;
    vector<char> titles;
    for(auto &c : line){
        if(c == ' '){
           if(!title.empty()){
              titles.push_back(title[0]);
           }
        title.clear();
        }
        else{
            title += c;
            if(title.length() > 1){
                return -2;
            }
        }
    }
    titles.push_back(title[0]);

    vector<vector<int>> numbers;
    while(getline(iFile, line)){
        vector<int> row;
        for(int i = 0; i < line.length(); ++i){
            if(line[i] == '0' || line[i] == '1'){
               if(i != line.length() - 1 && line[i+1] != ' '){
                   return -2;
               }
               row.push_back(line[i] - '0');
            }
            else if(line[i] != ' '){
               return -2;
            }
        }
        if(!numbers.empty() && row.size() != numbers[0].size()){
            return -3;
        }
        numbers.push_back(row);
    }
    if(numbers.size() != numbers[0].size()){
        return -3;
    }
    for(int i = 0; i < numbers.size(); ++i){
        if (numbers[i][i] != 0){
            return -4;
        }
    }
    graph->setVertices(titles, numbers);
    iFile.close();
    return 1;
}



void TParsing::error(const short& response) {
    if(response == -1){
        QMessageBox::information(nullptr, "Cancelled", "File wasn't selected");
    }
    else if(response == -2){
        QMessageBox::critical(nullptr, "Error №2", "Invalid Input error");
    }
    else if(response == -3){
        QMessageBox::critical(nullptr, "Error №3", "Invalid Size error");
    }
    else if(response == -4){
        QMessageBox::critical(nullptr, "Error №4", "Non-Zero Diagonals error");
    }
    else{
        QMessageBox::critical(nullptr, "Error №5", "Unknown error");
    }
}
