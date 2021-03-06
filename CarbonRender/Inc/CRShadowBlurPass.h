#ifndef CR_BLURPASS
#define CR_BLURPASS

#include "..\Inc\CRRenderPass.h"

class ShadowBlurPass : public RenderPass
{
private:
	void GetReady4Render(PassOutput* input);
	void Render(PassOutput* input);

	float stepSize = 1.0f;
	GLuint tempRt;
public:
	void Init();
};

#endif