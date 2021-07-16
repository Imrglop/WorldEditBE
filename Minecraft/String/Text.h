#pragma once
#include <iostream>
#include <string.h>

namespace Minecraft {
	class Text {
	public:
		union {
			char* szText;
			char strBuf[16];
		};
		size_t textSize;
		size_t textSizeAligned;
		std::string
#ifndef _DEBUG
			& 
#endif
			str() {
#if _DEBUG
			std::string placeHolder = std::string(textSizeAligned > 15 ? szText : strBuf);
			return placeHolder;
#else
			return *(std::string*)this;
#endif
		}

		// not working
		[[deprecated]]
		inline void setText(std::string text) {
			if (text.size() > 15) {
				this->szText = (char*)text.c_str();
			}
			else {
				for (size_t i = 0; i < strlen(szText); i++) {
					this->strBuf[i] = szText[i];
				}
			}
			this->textSize = text.size();
			this->textSizeAligned = text.size() | 15;
		}

		inline const char* getText() {
			if (this->textSize > 15) {
				return this->szText;
			}
			else {
				return this->strBuf;
			}
		}

		inline Text() {
			memset(this, 0, sizeof(Text));
		}

		inline void removeString() {
			if (this->textSize > 15) {
				free(this->szText);
			}
			memset(this, 0, sizeof(Text));
		}

		inline ~Text() {
			this->removeString();
		}
	};
}