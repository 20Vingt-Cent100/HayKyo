#include "vulkan/vulkan.h"

namespace HayKyo_Core {
	struct ApplicationInfo {
		const char* applicationName;
		uint32_t applicationVersion;
	};

	class Renderer {
	private:
		VkApplicationInfo m_appInfo{};

	public:
		Renderer();
		~Renderer();

		void bindAppInfo(ApplicationInfo* appInfo);
		void bindExtension(uint32_t extensionCount, const char** extensions);
	};
}