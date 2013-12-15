//
// Created by gin0606 on 2013/12/12.
//


#include "CCJson.h"


CCDictionary *CCJson::JSONObjectWithString(std::string jsonString) {
    return CCJson::JSONObjectWithString(jsonString.c_str());
}

CCDictionary *CCJson::JSONObjectWithString(const char *jsonString) {
    return CCJson::dictionaryWithJson(Json_create(jsonString));
}

CCDictionary *CCJson::dictionaryWithJson(Json *pJson) {
    CCObject *o = parseValue(pJson);
    if (!pJson->name) {
        return (CCDictionary *) o;
    } else {
        CCDictionary *pRet = CCDictionary::create();
        if (o) {
            pRet->setObject(o, pJson->name);
        }
        return pRet;
    }
}

CCObject *CCJson::parseObject(Json *pJson) {
    CCDictionary *root = CCDictionary::create();
    for (Json *item = pJson; item; item = item->next) {
        CCObject *value = parseValue(item);
        if (value) {
            root->setObject(value, item->name);
        }
    }
    return root;
}

CCArray *CCJson::parseArray(Json *pJson) {
    int arrayLength = Json_getSize(pJson);
    CCArray *array = CCArray::create();
    for (int i = 0; i < arrayLength; i++) {
        Json *item = Json_getItemAt(pJson, i);
        CCObject *object = parseValue(item);
        if (object) {
            array->addObject(object);
        }
    }
    return array;
}

CCObject *CCJson::parseValue(Json *pJsonValue) {
    if (!pJsonValue) {return NULL;}
    CCObject *object = NULL;
    switch (pJsonValue->type) {
        case Json_False:
            object = CCBool::create(false);
            break;
        case Json_True:
            object = CCBool::create(true);
            break;
        case Json_NULL:
            object = NULL;
            break;
        case Json_Number:
            object = CCFloat::create(pJsonValue->valuefloat);
            break;
        case Json_String:
            if (pJsonValue->valuestring) {
                object = CCString::create(pJsonValue->valuestring);
            }
            break;
        case Json_Array:
            object = parseArray(pJsonValue);
            break;
        case Json_Object:
            object = parseObject(pJsonValue->child);
            break;
        default:
            object = NULL;
            break;
    }
    return object;
}
