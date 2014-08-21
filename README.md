# [DEPRECATED]cocos2d-x-extention-CCJson

json string convert to CCDictionary

* object : CCDictionary
* array : CCArray
* string : CCString
* number : CCFloat
* true/false : CCBool
* null : NULL

## Usage

```
{
    "stringKey": "JSON_string",
    "numberKey": 111,
    "falseKey": false,
    "trueKey": true,
    "arrayKey": [
        "one",
        "two",
        "three"
    ],
    "objectKey": {
        "objects": "o"
    }
}
```

↓

```
CCDictionary *pDictionary = CCJson::JSONObjectWithString(jsonString);

CCString *ccString = (CCString *) pDictionary->objectForKey("stringKey");
ccString->getCString(); // => "JSON_string"

CCFloat *ccFloat = (CCFloat *) pDictionary->objectForKey("numberKey");

CCBool *ccBoolFalse = (CCBool *) pDictionary->objectForKey("falseKey");
ccBoolFalse->getValue(); // => false

CCBool *ccBoolTrue = (CCBool *) pDictionary->objectForKey("trueKey");
ccBoolTrue->getValue(); // => true

CCArray *ccArray = (CCArray *) pDictionary->objectForKey("arrayKey");
ccArray->count() // -> 3
```
