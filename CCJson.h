//
// Created by gin0606 on 2013/12/12.
//

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Json.h"

USING_NS_CC;
USING_NS_CC_EXT;

#ifndef __JsonUtil_H_
#define __JsonUtil_H_

NS_CC_EXT_BEGIN

class CCJson : public CCObject {
public:
    static CCDictionary *JSONObjectWithString(const char *jsonString);

    static CCDictionary *JSONObjectWithString(std::string jsonString);

private:
    static CCDictionary *dictionaryWithJson(Json *pJson);

    static CCObject *parseObject(Json *pJson);

    static CCArray *parseArray(Json *pJson);

    static CCObject *parseValue(Json *pJson);
};

NS_CC_EXT_END
#endif //__JsonUtil_H_
