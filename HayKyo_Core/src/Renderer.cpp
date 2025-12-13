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

void HayKyo_Core::Renderer::initVulkan() {
	if (m_createInfo.enabledExtensionCount != NULL && m_createInfo.ppEnabledExtensionNames != NULL)
	{
		createInstance();
		pickphysicalDevices();
		createLogicalDevice();
	}
}

void HayKyo_Core::Renderer::pickphysicalDevices() {
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(m_instance, &deviceCount, nullptr);

	if (deviceCount == 0)
		throw std::runtime_error("Could Not find a compatible GPU");

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(m_instance, &deviceCount, devices.data());

	for (const auto& device : devices) {
		if (isDeviceSuitable(device)) {
			physicalDevice = device;
			break;
		}
	}

	if (physicalDevice == VK_NULL_HANDLE)
		throw std::runtime_error("No suitable GPU");
}

bool HayKyo_Core::Renderer::isDeviceSuitable(VkPhysicalDevice device) {
	HayKyo_Core::QueueFamilyIndices indices = findQueueFamilies(device);



	return indices.isComplete();
}

HayKyo_Core::QueueFamilyIndices HayKyo_Core::Renderer::findQueueFamilies(VkPhysicalDevice device) {
	HayKyo_Core::QueueFamilyIndices indices;

	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

	int i = 0;
	for (const auto& queueFamily : queueFamilies) {
		if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			indices.graphicsFamily = i;
		}

		if (indices.isComplete())
			break;

		i++;
	}

	return indices;
}

void HayKyo_Core::Renderer::createLogicalDevice() {

}


HayKyo_Core::Renderer::~Renderer(){}