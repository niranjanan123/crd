#ifndef __JSON_HANDLER_H__
#define __JSON_HANDLER_H__
#include <iostream>
#include <json/json.h>
#include <iostream>
#include <string>
class JSONHandler
{
	public:
	std::string convertToString(Json::Value&);
	Json::Value convertToJSON(std::string);
};
#endif
