#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <fstream>

#include "Point2.h"


class JSonOutput {

    std::string FileName{"data.json"};

    public:
    // Constructors
    JSonOutput(){};
    JSonOutput(std::string& fileName);

    //Behaviors
    void outputPoint(const Point2& point);

    private: //Private Helpers
    json serializePoint(const Point2& point);



};