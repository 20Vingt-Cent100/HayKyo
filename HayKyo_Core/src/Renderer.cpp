#include "Renderer.h"

HayKyo_Core::Renderer::Renderer(){
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &m_appInfo;
	createInfo.enabledExtensionCount = extensionCount;
	createInfo.ppEnabledExtensionNames = extensions;
}

void HayKyo_Core::Renderer::bindAppInfo(ApplicationInfo* appInfo){
	m_appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	m_appInfo.pNext = NULL;
	m_appInfo.pApplicationName = appInfo->applicationName;
	m_appInfo.applicationVersion = appInfo->applicationVersion;
	m_appInfo.pEngineName = "HayKyo";
	m_appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 1);
	m_appInfo.apiVersion = VK_API_VERSION_1_0;
}

void HayKyo_Core::Renderer::bindExtension(uint32_t extensionCount, const char** extensions) {

}


HayKyo_Core::Renderer::~Renderer(){}