#pragma once
#include "Component.hpp"

#include <string>
#include <vector>
#include <memory>
#include <thread>

namespace moduru {
	namespace gui {
		class BMFParser;
	}
}

namespace mpc {
	namespace lcdgui {
		class TextComp
			: public Component

		{
		private:
			static moduru::gui::BMFParser* bmfParser;

		protected:
			bool inverted{ false };
			bool noLeftMargin{ false };

		protected:
			unsigned int x{ 0 };
			unsigned int y{ 0 };
			unsigned int w{ 0 };
			unsigned int h{ 0 };

			bool scrolling{ false };
			std::thread scrollThread;

		protected:
			const int TEXT_HEIGHT = 7;
			const int TEXT_WIDTH = 6;

		protected:
			std::string name{ "" };
			std::	string text{ "" };
			int columns{ 0 }; // characters
			bool opaque{ true };

		private:
			void initRECT();
			void scroll();

		private:
			static void static_scroll(void * args);

		public:
			virtual void setSize(int width, int height);
			virtual void setLocation(int x, int y);
			virtual void setText(std::string s);

		public:
			void setOpaque(bool b);
			void setInverted(bool b);
			void setNoLeftMargin(bool b);
			int getX();
			int getY();
			int getW();
			int getH();
			std::string getText();
			int getColumns();
			void setColumns(int i);
			std::string getName();
			void setTextPadded(std::string s, std::string padding);
			void setTextPadded(int i, std::string padding);
			void setScrolling(bool scrolling);
			unsigned int GetTextEntryLength();

		public:
			void Draw(std::vector<std::vector<bool> >* pixels) override;

		public:
			TextComp();
			virtual ~TextComp();

		};

	}
}