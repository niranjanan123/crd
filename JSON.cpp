#include "JSONHandler.h"
std::string JSONHandler::convertToString(Json::Value &obj)
{
    return obj.toStyledString();
}
Json::Value JSONHandler::convertToJSON(std::string str)
{
   Json::Value value(str );
   return value;
}
