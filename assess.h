#ifndef __DATA_HANDLER_H__
#define __DATA_HANDLER_H__

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>
#include <iostream>
#include <map>
#include <mutex>

class DataHandler
{
  public:
  DataHandler();
  bool insertData(std::string,Json::Value &,long long timeToLive = 0);
  Json::Value readData(std::string);
  bool deleteData(std::string);
  void setFilePath(std::string);
  private:
  static DataHandler *instance;
  std::map<std::string,std::string> dataStorage;
  std::map<std::string,long long> timeToLive;
  bool checkIfDataExistMap(std::string key);
  std::string getDataFromMap(std::string key);
  bool deleteFromMap(std::string);
  bool insertIntoMap(std::string,std::string,long long timeToLive = 0);
  int writeDataToFile(std::string,std::string);
  int readDataFromFile();
  int deleteFromFile();
  std::mutex dataCriticalMutex;
  std::mutex instanceMutex;
  std::mutex tll_mutex;
  void updateFilesWithMapData();
  DataHandler * getInstance();
  void resetInstance();
  std::string filePath;
  void lockMutex();
  void unLockMutex();
  void purgeData(); 
  
};
#endif
