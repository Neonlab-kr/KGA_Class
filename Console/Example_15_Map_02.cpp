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
	sceneManager.addScene("MainMenu", new Scene("���� �޴� Scene"));
	sceneManager.addScene("Battle", new Scene("���� Scene"));

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
	scenes[name] = scene;//scene�� �̸��� Ű�� �ϰ� �����͸� ������ �����Ѵ�.
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
		std::cout << "�ش� Scene ����" << std::endl;
	}
}
