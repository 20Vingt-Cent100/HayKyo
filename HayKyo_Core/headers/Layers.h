#pragma once
#include <Event.h>
#include <vector>
#include <RenderObject.h>

namespace HayKyo_Core {
	class Layer {
	public:
		virtual void onRender();
		virtual void onEvent(const Event& e);
		void hide() { isVisible = false; }
		void show() { isVisible = true; }

		std::vector<HayKyo_Core::RenderObject> m_objectList;

	private:

		bool isVisible = true;
	};
}