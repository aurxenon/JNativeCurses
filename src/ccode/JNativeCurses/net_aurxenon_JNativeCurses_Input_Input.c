/* DO NOT EDIT THIS FILE - it is machine generated */
/* Header for class net_aurxenon_JNativeCurses_Input_Input */

#include "net_aurxenon_JNativeCurses_Input_Input.h"

JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Input_Input_inputInit(JNIEnv *env, jobject obj)
{
    Java_net_aurxenon_JNativeCurses_Input_Input_disableKeyDelay(env, obj);
    Java_net_aurxenon_JNativeCurses_Input_Input_disableEcho(env, obj);
    Java_net_aurxenon_JNativeCurses_Input_Input_disableLongText(env, obj);
}
JNIEXPORT jint JNICALL Java_net_aurxenon_JNativeCurses_Input_Input_readInput(JNIEnv *env, jobject obj)
{
    return (jint)getch();
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Input_Input_enableKeyDelay(JNIEnv *env, jobject obj)
{
    nodelay(stdscr, FALSE);
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Input_Input_disableKeyDelay(JNIEnv *env, jobject obj)
{
    nodelay(stdscr, TRUE);
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Input_Input_enableEcho(JNIEnv *env, jobject obj)
{
    echo();
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Input_Input_disableEcho(JNIEnv *env, jobject obj)
{
    noecho();
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Input_Input_enableLongText(JNIEnv *env, jobject obj)
{
    cbreak();
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Input_Input_disableLongText(JNIEnv *env, jobject obj)
{
    nocbreak();
}
