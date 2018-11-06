#pragma once

#ifdef MAMLATENGINEPUB_EXPORT
#define MAMLATENGINEPUB_API __declspec(dllexport)
#else
#define MAMLATENGINEPUB_API __declspec(dllimport)
#endif