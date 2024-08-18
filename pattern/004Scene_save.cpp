#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <unordered_map>
#include <sstream>

//我真在编写场景图 测试递归保存和加载的代码 使用多态处理不同节点的函数调用 文字处理代码比较笨拙

void parseLine(const std::string& line, std::string& type, std::string& name, int& actorNum) {
    std::istringstream iss(line);
    std::string temp;

    // Read and discard the "Type:" label
    iss >> temp >> type;

    // Read and discard the "Name:" label
    iss >> temp >> name;

    // Read and discard the "ActorNum:" label
    iss >> temp >> actorNum;
}


class RTTIBase {
public:
    virtual const char* getTypeName() const = 0;
    virtual ~RTTIBase() = default;
};

class Actor : public RTTIBase
{
public:
    static int count;
    int id;
    std::string name;
    int age;
    Actor* father;
    Actor(std::string name):name(name){id = count ; count++;}
    Actor(std::string name, int age):name(name), age(age){id = count ; count++;}
    // 希望层级输出时有推进关系  当渲染引擎计算层次包围盒 或 层次变换时 道理类似
    // 当每个层次调用此函数时 累加空格数 形成层次效果
    void printSpace(int len)
    {
        for(int i= 0; i<len; i++)
        {
            std::cout<<" ";
        }
    }

    void SaveSpace(std::ofstream& file, int len)
    {
        for(int i= 0; i<len; i++)
        {
            file<<" ";
        }
    }

    virtual void outputInfo(int space = 0)
    {
        printSpace(space);
        std::cout<<"Name: "<< name <<" Age: "<< age <<" ID: "<< id <<std::endl;
    }
    void changeName(std::string name)
    {
        this->name = name;
    }

    virtual void ChangeActorName( std::string oldName, std::string newName)
    {
        std::cout<< name << oldName <<std::endl;
        if(name == oldName)
        {
            name = newName;
            std::cout<<"name changed\n";
        }
    }

    virtual Actor* copy()
    {
        return new Actor(name, age);
    }

    const char* getTypeName() const override {
        return "Actor";
    }

    virtual void save(std::ofstream& file, int space = 0)
    {
        SaveSpace(file, space);
        file<<"Type: " << getTypeName() << " Name: "<<name<<" Age: "<<age<<std::endl;
    }

    virtual void addActor(Actor* actor) {
        std::cerr << "Actor::addActor() must be called on a Group or scene." << std::endl;
    }

    void load(std::ifstream& file, Actor* father = nullptr)
    {
    }
    
};

int Actor::count = 0;

class Group : public Actor
{
    int mActorNum = 0;
public:
    std::vector<Actor*> children;
    Group(std::string name):Actor(name){ }
    void addActor(Actor* actor) override
    {
        children.push_back(actor);
        actor->father = this;
        mActorNum++;
    }

    void outputInfo(int space = 0)override
    {
        printSpace(space);
        std::cout<<"----------------- "<<std::endl;
        printSpace(space);
        std::cout<<"Group name: "<<name<<" ID: "<< id <<std::endl;

        space += 7;//! 递归调用时 空格数增加
        for(auto child:children)
        {
            child->outputInfo(space);
        }
    }

    void ChangeActorName( std::string oldName, std::string newName)override
    {
        for(auto child:children)
        {
            child->ChangeActorName(oldName, newName);
        }
    }
    

    Actor* copy()override
    {
        Group* group = new Group(name);
        for(auto child:children)
        {
            group->addActor(child->copy());
        }
        return group;
    }

    const char* getTypeName() const override {
        return "Group";
    }

    void save(std::ofstream& file, int space = 0)override
    {
        SaveSpace(file, space);
         
        file<<"Type: " << getTypeName() << " Name: "<<name<<" ActorNum: "<<mActorNum<<std::endl;

        SaveSpace(file, space);
        file << "{\n";

        space += 2;
        for(auto child:children)
        {
            child->save(file, space);
        }

        space -= 2;
        SaveSpace(file, space);
        file << "}\n";
    }

    void load(std::ifstream& file, int groupActorNum) {
        std::string line;
        std::getline(file, line);
        //std::cout<<groupActorNum<<std::endl;
    for (int i = 0; i < groupActorNum; i++) {
        
        std::getline(file, line);
        
        std::string type, name;
        int num;
        parseLine(line, type, name, num);

        if (type == "Group") {
            Group* group = new Group(name);
            group->load(file, num);
            addActor(group);
        } else if (type == "Actor") {
            Actor* actor = new Actor(name, num); // Assuming num is age for Actor
            addActor(actor);
        } else {
            std::cerr << "Unknown type: " << type << std::endl;
        }
    }
    std::getline(file, line);
    }

};

class Scene 
{
    int actorNum = 0;
    std::vector<Actor*> actors;
public:
    void addActor(Actor* actor)
    {
        actors.push_back(actor);
        actorNum++;
    }
    void outputInfo()
    {
        for(auto actor:actors)
        {
            actor->outputInfo();
        }
    }

    void save(const std::string& filename ) {
        std::ofstream file(filename);
        for(auto actor:actors)
        {
            actor->save(file);
        }
        file.close();
        
    }

    void loadScene(const std::string& filename) {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            std::string line;
            while (std::getline(inFile, line)) {
                std::string type, name;
                //std::cout<<line<<std::endl;
                int actorNum;
                parseLine(line, type, name, actorNum);

                if (type == "Group") {
                    Group* group = new Group(name);
                    group->load(inFile, actorNum);
                    addActor(group);
                    // Add group to the scene
                } else if (type == "Actor") {
                    Actor* actor = new Actor(name, actorNum); // Assuming actorNum is age for Actor
                    addActor(actor);
                    // Add actor to the scene
                } else {
                    std::cerr << "Unknown type: " << type << std::endl;
                }
            }
            inFile.close();
        } else {
            std::cerr << "Unable to open file" << std::endl;
        }
        }
    void ChangeActorName( std::string oldName, std::string newName)
    {
        for(auto actor:actors)
        {
            actor->ChangeActorName(oldName, newName);
        }
    }
};


int main()
{ 
    Scene scene = Scene();
    // scene.addActor(group1);
    // scene.addActor(actor1);
    // scene.save("scene.txt");
    scene.loadScene("readThis.txt");
    
    scene.ChangeActorName("actor3", "heqin");
    scene.outputInfo();

    scene.save("saveFromreadThis.txt");
    return 0;
}




 


 