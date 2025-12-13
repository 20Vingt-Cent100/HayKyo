#pragma once
#include "vulkan/vulkan.h"
#include <stdexcept>
#include <vector>
#include <optional>

namespace HayKyo_Core {
	struct ApplicationInfo {
		const char* applicationName;
		uint32_t applicationVersion;
	};

	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;

		bool isComplete() {
			return graphicsFamily.has_value();
		}
	};

	class Renderer {
	private:
		VkInstance m_instance = nullptr;
		VkDevice m_device = nullptr;

		VkApplicationInfo m_appInfo{};
		VkInstanceCreateInfo m_createInfo{};



		void pickphysicalDevices();
		void createInstance();

		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
		bool isDeviceSuitable(VkPhysicalDevice device);

		void createLogicalDevice();

	public:
		Renderer();
		~Renderer();

		void bindAppInfo(ApplicationInfo* appInfo);
		void bindExtension(uint32_t extensionCount, const char** extensions);
		
		void destroyInstance();
		void initVulkan();
		
	};


	
}