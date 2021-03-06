#include "working_directory.h"

namespace WorkingDir{

    WorkingDirectory::WorkingDirectory(const QString& _path){
            path = _path;
    }

    bool WorkingDirectory::IsValidDir(const QString& _path){
        QDir dir( _path );
        if( !dir.exists() ){
            return false;
        }

        return true;
    }

    bool WorkingDirectory::IsValidDir(void){
        QDir dir( path );
        if( !dir.exists() ){
            return false;
        }

        return true;
    }

    int WorkingDirectory::Size(){
        return namesOfSongs.size();
    }

    QString WorkingDirectory::GetSong(const unsigned int i){
        if( (0 <= i) && (i < namesOfSongs.size()) ){
            return namesOfSongs[i];
        } else {
            return "";
        }
    }

    bool WorkingDirectory::Refresh(TypeOfSort typeOfSort)
    {
        /*
        Функция считывает список файлов (только доступные для чтения) в директории.
        Входные параметры:
         typeOfSort - тип сортировки
        Возвращаемое значение:
         true - в случае успеха операции
         false - в противном случае
        */
        QDir dir(path);

        if( dir.exists() ){
            dir.setFilter(QDir::Files | QDir::Readable | QDir::NoSymLinks);
            switch( typeOfSort ) {
                case ALPHABET: dir.setSorting(QDir::Name);
                        break;

                case RANDOM: dir.setSorting(QDir::NoSort);
                        break;


                default: dir.setSorting(QDir::Unsorted);
            }

            QFileInfoList dirInfoList = dir.entryInfoList();

            for (int i = 0; i < dirInfoList.size(); i++) {
                QFileInfo fileInfo = dirInfoList.at(i);

                // заполняем вектор названиями песен
                namesOfSongs.push_back( fileInfo.fileName() );
            }
        }

        return listOfSongs;
    }


};

