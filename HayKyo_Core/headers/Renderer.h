#pragma once
#include <vulkan/vulkan.h>

#include <iostream>
#include <vector>
#include <optional>

namespace HayKyo_Core {
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;

		bool isComplete() {return graphicsFamily.has_value();}
	};

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void initVulkan(const char* appName, const std::vector<const char*>& extensions);
		
	private:
		VkInstance m_instance;
		VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
		VkDevice m_device;

		void createInstance(const char* appName, const std::vector<const char*>& extensions);

		void pickPhysicalDevice();
		bool isDeviceSuitable(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

		void createLogicalDevice();
	};
}