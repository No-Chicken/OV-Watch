#ifndef VERSION_H
#define VERSION_H

#ifdef __cplusplus
extern "C" {
#endif


/***************************
 * CURRENT VERSION OF OV-Watch
 ***************************/
/**
 * total mechanical structure change will show in major
 * hardware change will show in minor
 * software change will show in patch
 *
 */
#define VERSION_MAJOR 2
#define VERSION_MINOR 4
#define VERSION_PATCH 4
#define VERSION_INFO ""

/**
 * No-Chicken的意思是no spring chicken any more...
 * 
 */
#define VERSION_AUTHOR_ENG_NAME    "No-Chicken"
#define VERSION_AUTHOR_CN_NAME     "不吃油炸鸡"
#define VERSION_PROJECT_LINK       "https://github.com/No-Chicken/OV-Watch"


/**
 * Wrapper functions for VERSION macros
 */

static inline int watch_version_major(void)
{
    return VERSION_MAJOR;
}

static inline int watch_version_minor(void)
{
    return VERSION_MINOR;
}

static inline int watch_version_patch(void)
{
    return VERSION_PATCH;
}

static inline const char *watch_version_info(void)
{
    return VERSION_INFO;
}

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
