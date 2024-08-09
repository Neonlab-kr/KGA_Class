#include <iostream>
#include <map>
#include <conio.h>

class Scene
{
private:
	std::string desc;

public:
	Scene() :desc("") {}
	Scene(const std::string& desc) :desc(desc) {}
	std::string getDesc() const { return desc; }
};

class SceneManager
{
private:
	std::map<std::string, Scene*> scenes;
	Scene* currentScene;
	std::string currentSceneName;

public:
	SceneManager() : currentScene(nullptr), currentSceneName("") {}
	~SceneManager();

	void addScene(const std::string& name, Scene* scene);
	void removeScene(const std::string& name);
	void showCurrentScene() const;
	void setScene(const std::string& name);

};

int main()
{
	SceneManager sceneManager;
	sceneManager.addScene("MainMenu", new Scene("메인 메뉴 Scene"));
	sceneManager.addScene("Battle", new Scene("전투 Scene"));

	sceneManager.setScene("MainMenu");
	sceneManager.showCurrentScene();

	_getch();

	sceneManager.setScene("Battle");
	sceneManager.showCurrentScene();

	return 0;
}

SceneManager::~SceneManager()
{
	for (auto& i : scenes)
	{
		delete i.second;
		i.second = nullptr;
	}
}

void SceneManager::addScene(const std::string& name, Scene* scene)
{
	scenes[name] = scene;//scene의 이름을 키로 하고 포인터를 값으로 저장한다.
}

void SceneManager::removeScene(const std::string& name)
{
	std::map<std::string, Scene*>::iterator iter = scenes.find(name);
	if (iter != scenes.end())
	{
		delete iter->second;
		iter->second = nullptr;
		scenes.erase(iter);
	}
}

void SceneManager::showCurrentScene() const
{
	//if(currentSceneName.empty()) return
	if (currentScene)
	{
		system("cls");
		std::cout << '[' << currentSceneName << ']' << std::endl;
		std::cout << currentScene->getDesc();
	}
}

void SceneManager::setScene(const std::string& name)
{
	std::map<std::string, Scene*>::iterator iter = scenes.find(name);
	if (iter != scenes.end())
	{
		currentScene = iter->second;
		currentSceneName = name;
	}
	else
	{
		std::cout << "해당 Scene 없음" << std::endl;
	}
}
