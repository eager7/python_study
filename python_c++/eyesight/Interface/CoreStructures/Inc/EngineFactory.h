#ifndef __EngineFactory_H_
#define __EngineFactory_H_

#include "Ctrl.h"
#include "CoreStructures.h"
#include "ConfigManager.h"
#if defined(VS) && (defined(CORE_EXPORTS) || defined(CORE_IMPORTS))

	#ifdef CORE_EXPORTS
	#define CORE_FACTORY extern "C" __declspec(dllexport)

	#elif defined(CORE_IMPORTS)	&& defined(MANAGED)
	#define CORE_FACTORY __declspec(dllimport)

	#elif defined(CORE_IMPORTS)
	#define CORE_FACTORY extern "C" __declspec(dllimport)
	#else
	#define CORE_FACTORY
	#endif


//class EngineFactory
//{
//public:
	CORE_FACTORY Ctrl* createEngine(VideoConfig sVideoConfig,int tConfigType,char *pConfigFileName);
	CORE_FACTORY Ctrl* createEngineByConfig(VideoConfig sVideoConfig,ConfigManager *pConf);

	CORE_FACTORY void destroyEngine(Ctrl* pEngine);
//};
#else

class eyeSight
{
	public:
		static Ctrl* createEngine(VideoConfig sVideoConfig,int tConfigType,char *pConfigFileName);
		static Ctrl* createEngineByConfig(VideoConfig sVideoConfig,ConfigManager *pConf);
		static void destroyEngine(Ctrl* pEngine);
};
#define CORE_FACTORY
#endif
#endif
