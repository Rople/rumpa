#pragma once

#ifndef BASEELEMENT_H
#define BASEELEMENT_H

class CBaseElement  {
public:
	virtual void Draw() = 0;
	virtual void OnClick(int mouseX, int mouseY) = 0;
	virtual void OnHover(int mouseX, int mouseY) = 0;
};

#endif // !BASEELEMENT_H