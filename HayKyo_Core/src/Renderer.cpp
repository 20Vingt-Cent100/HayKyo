#include "Renderer.h"

HayKyo_Core::Renderer::Renderer(){
	m_createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
}

void HayKyo_Core::Renderer::bindAppInfo(ApplicationInfo* appInfo){
	m_appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	m_appInfo.pNext = NULL;
	m_appInfo.pApplicationName = appInfo->applicationName;
	m_appInfo.applicationVersion = appInfo->applicationVersion;
	m_appInfo.pEngineName = "HayKyo";
	m_appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 1);
	m_appInfo.apiVersion = VK_API_VERSION_1_0;

	m_createInfo.pApplicationInfo = &m_appInfo;
	m_createInfo.enabledLayerCount = 0;
}

void HayKyo_Core::Renderer::bindExtension(uint32_t extensionCount, const char** extensions) {
	m_createInfo.enabledExtensionCount = extensionCount;
	m_createInfo.ppEnabledExtensionNames = extensions;
}

void HayKyo_Core::Renderer::createInstance() {
	if (vkCreateInstance(&m_createInfo, nullptr, &m_instance) != VK_SUCCESS) {
		throw std::runtime_error("failed to create instance!");
	}
}

void HayKyo_Core::Renderer::destroyInstance() {
	vkDestroyInstance(m_instance, nullptr);
}


HayKyo_Core::Renderer::~Renderer(){}