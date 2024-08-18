#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Helper function to print spaces
void printSpace(int space) {
    for (int i = 0; i < space; ++i) {
        std::cout << " ";
    }
}

class TypeRegistry {
public:
    static TypeRegistry& instance() {
        static TypeRegistry instance;
        return instance;
    }

    void registerType(const std::string& typeName, int typeId) {
        typeMap[typeName] = typeId;
        idMap[typeId] = typeName;
    }

    int getTypeId(const std::string& typeName) {
        return typeMap[typeName];
    }

    std::string getTypeName(int typeId) {
        return idMap[typeId];
    }

private:
    std::unordered_map<std::string, int> typeMap;
    std::unordered_map<int, std::string> idMap;
};

class RTTIBase {
public:
    virtual int getTypeId() const = 0;
    virtual ~RTTIBase() = default;
};

class Actor : public RTTIBase {
public:
    std::string name;
    int age;
    int id;
    static int num;
    Actor* father;

    Actor(std::string name, int age = 0) : name(name), age(age), father(nullptr) {
        num++;
    }

    virtual Actor* copy() {
        return new Actor(name, age);
    }

    int getTypeId() const override {
        return TypeRegistry::instance().getTypeId("Actor");
    }

    virtual void outputInfo(int space = 0) {
        // Implementation of outputInfo
    }
};

int Actor::num = 0;

class Group : public Actor {
public:
    std::vector<Actor*> children;

    Group(std::string name) : Actor(name) { }

    void addActor(Actor* actor) {
        children.push_back(actor);
        actor->father = this;
    }

    void outputInfo(int space = 0) override {
        printSpace(space);
        std::cout << "----------------- " << std::endl;
        printSpace(space);
        std::cout << "Group name: " << name << " ID: " << id << std::endl;

        space += 7; // Increase space for recursive call
        for (auto child : children) {
            child->outputInfo(space);
        }
    }

    int getTypeId() const override {
        return TypeRegistry::instance().getTypeId("Group");
    }
};



int main() {
    TypeRegistry::instance().registerType("Actor", 1);
    TypeRegistry::instance().registerType("Group", 2);

    Actor* actor = new Actor("John Doe", 30);
    Group* group = new Group("Group A");

    std::cout << "Actor type ID: " << actor->getTypeId() << std::endl;
    std::cout << "Group type ID: " << group->getTypeId() << std::endl;

    std::cout << "Actor type name: " << TypeRegistry::instance().getTypeName(actor->getTypeId()) << std::endl;
    std::cout << "Actor type name: " << TypeRegistry::instance().getTypeName(group->getTypeId()) << std::endl;

    delete actor;
    delete group;

    return 0;
}