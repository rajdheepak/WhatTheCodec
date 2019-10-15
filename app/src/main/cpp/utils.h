//
// Created by Alexander Berezhnoi on 25/03/19.
//

#ifndef WHATTHECODEC_UTILS_H
#define WHATTHECODEC_UTILS_H

#include <jni.h>

/**
 * Initializes the fields struct that keeps handles to VideoFileConfig's internal fields in order to read/write to them.
 */
int utils_fields_init(JavaVM *vm);

/**
 * Frees resources created in utils_fields_init(JavaVM *vm).
 */
void utils_fields_free(JavaVM *vm);

/**
 * Returns a pointer to JNIEnv struct to use in various JNI-specific functions.
 */
JNIEnv *utils_get_env();

/**
 * Helper function for calling an instance methods of Java objects with arbitrary arguments.
 *
 * @param instance Java object to call a method on
 * @param methodID an ID of a method to call
 * @param ... arguments to pass to the method
 */
void utils_call_instance_method(jobject instance, jmethodID methodID, ...);

// The approach was taken from here:
// https://code.videolan.org/videolan/vlc-android/blob/master/libvlc/jni/utils.h
// https://code.videolan.org/videolan/vlc-android/blob/master/libvlc/jni/libvlcjni.c

struct fields {
    struct {
        jclass clazz;
        jfieldID nativePointer;
        jfieldID fullFeatured;
    } VideoStream;
    struct {
        jclass clazz;
        jmethodID onVideoConfigFoundID;
        jmethodID onVideoStreamFoundID;
        jmethodID onErrorID;
    } VideoFileConfigBuilder;
};

extern struct fields fields;

#endif //WHATTHECODEC_UTILS_H
