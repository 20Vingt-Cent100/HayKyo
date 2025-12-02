#include "vulkan/vulkan.h"
#include <stdexcept>

namespace HayKyo_Core {
	struct ApplicationInfo {
		const char* applicationName;
		uint32_t applicationVersion;
	};

	class Renderer {
	private:
		VkInstance m_instance;

		VkApplicationInfo m_appInfo{};
		VkInstanceCreateInfo m_createInfo{};

	public:
		Renderer();
		~Renderer();

		void bindAppInfo(ApplicationInfo* appInfo);
		void bindExtension(uint32_t extensionCount, const char** extensions);
		void createInstance();
		void destroyInstance();
	};
}