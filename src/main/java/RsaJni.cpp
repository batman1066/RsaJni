#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <jni.h>
/* 1
 * Class:     jni_RsaJni
 * Method:    encryptRsaByPublicKey
 * Signature: ([BLjava/lang/String;)[B
 */
extern "C"
JNIEXPORT jbyteArray JNICALL Java_jni_RsaJni_encryptRsaByPublicKey(JNIEnv *env, jobject obj, jbyteArray message, jstring publicKey) {
    // Convert message bytes to char array
    jbyte* bytes = env->GetByteArrayElements(message, NULL);
    const char* msg = reinterpret_cast<char*>(bytes);
    int ciphertext_len = env->GetArrayLength(message);
    // Read public key from file
    /*const char* path = env->GetStringUTFChars(publicKeyPath, 0);
    FILE* pubFile = fopen(path, "r");
    RSA* rsa = PEM_read_RSA_PUBKEY(pubFile, NULL, NULL, NULL);
    fclose(pubFile);
    env->ReleaseStringUTFChars(publicKeyPath, path);*/
    const char* nativeStringKey = env->GetStringUTFChars(publicKey, NULL);
    //

    BIO* keybio = BIO_new_mem_buf(nativeStringKey, -1);
    RSA* rsa = RSA_new();
    rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, NULL, NULL);
   

    // Encrypt message with public key
    unsigned char encrypted[2048];
    int len = RSA_public_encrypt(ciphertext_len, (unsigned char*) msg, encrypted, rsa, RSA_PKCS1_PADDING);

    // Create byte array for encrypted message
    jbyteArray result = env->NewByteArray(len);
    env->SetByteArrayRegion(result, 0, len, (jbyte*) encrypted);

    // Clean up
    RSA_free(rsa);
    BIO_free_all(keybio);
    env->ReleaseStringUTFChars(publicKey, nativeStringKey);
    env->ReleaseByteArrayElements(message, bytes, 0);

    return result;
}
/* 2
 * Class:     jni_RsaJni
 * Method:    decryptRsaByPrivateKey
 * Signature: ([BLjava/lang/String;)[B
 */
extern "C"
JNIEXPORT jbyteArray JNICALL Java_jni_RsaJni_decryptRsaByPrivateKey(JNIEnv *env, jobject obj, jbyteArray message, jstring privateKey) {
    // Convert message bytes to char array
    jbyte* bytes = env->GetByteArrayElements(message, NULL);
    const char* msg = reinterpret_cast<char*>(bytes);
    int ciphertext_len = env->GetArrayLength(message);

    // Read private key from file
   /* const char* path = env->GetStringUTFChars(privateKeyPath, 0);
    FILE* privFile = fopen(path, "r");
    RSA* rsa = PEM_read_RSAPrivateKey(privFile, NULL, NULL, NULL);
    fclose(privFile);
    env->ReleaseStringUTFChars(privateKeyPath, path);*/
    const char* nativeStringKey = env->GetStringUTFChars(privateKey, NULL);
    //

    RSA* rsa = RSA_new();
    BIO* keybio;
    keybio = BIO_new_mem_buf(nativeStringKey, -1);
    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);
    //

    // Decrypt message with private key
    unsigned char decrypted[2048]; 
    int len = RSA_private_decrypt(ciphertext_len, (unsigned char*) msg, decrypted, rsa, RSA_PKCS1_PADDING);

    // Create byte array for decrypted message
    jbyteArray result = env->NewByteArray(len);
    env->SetByteArrayRegion(result, 0, len, (jbyte*) decrypted);

    // Clean up
    RSA_free(rsa);
    BIO_free_all(keybio);
    env->ReleaseStringUTFChars(privateKey, nativeStringKey);

    env->ReleaseByteArrayElements(message, bytes, 0);

    return result;
}
/* 3
 * Class:     jni_RsaJni
 * Method:    encryptRsaByPrivateKey
 * Signature: ([BLjava/lang/String;)[B
 */
extern "C"
JNIEXPORT jbyteArray JNICALL Java_jni_RsaJni_encryptRsaByPrivateKey(JNIEnv *env, jobject obj, jbyteArray message, jstring privateKey) {
    // Convert message bytes to char array
    jbyte* bytes = env->GetByteArrayElements(message, NULL);
    const char* msg = reinterpret_cast<char*>(bytes);
    int ciphertext_len = env->GetArrayLength(message);
    //
    // Read private key from file
   /* const char* path = env->GetStringUTFChars(privateKeyPath, 0);
    FILE* privFile = fopen(path, "r");
    RSA* rsa = PEM_read_RSAPrivateKey(privFile, NULL, NULL, NULL);
    fclose(privFile);
    env->ReleaseStringUTFChars(privateKeyPath, path);*/
    const char* nativeStringKey = env->GetStringUTFChars(privateKey, NULL);

    //

    RSA* rsa = RSA_new();
    BIO* keybio;
    keybio = BIO_new_mem_buf(nativeStringKey, -1);
    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);



    // Encrypt message with public key
    unsigned char encrypted[2048];
    int len = RSA_private_encrypt(ciphertext_len, (unsigned char*) msg, encrypted, rsa, RSA_PKCS1_PADDING);

    // Create byte array for encrypted message
    jbyteArray result = env->NewByteArray(len);
    env->SetByteArrayRegion(result, 0, len, (jbyte*) encrypted);

    // Clean up
    RSA_free(rsa);
    BIO_free_all(keybio);
    env->ReleaseStringUTFChars(privateKey, nativeStringKey);
    env->ReleaseByteArrayElements(message, bytes, 0);

    return result;
}
/* 4
 * Class:     jni_RsaJni
 * Method:    decryptRsaByPublicKey
 * Signature: ([BLjava/lang/String;)[B
 */
extern "C"
JNIEXPORT jbyteArray JNICALL Java_jni_RsaJni_decryptRsaByPublicKey(JNIEnv *env, jobject obj, jbyteArray message, jstring publicKey) {
    // Convert message bytes to char array
    jbyte* bytes = env->GetByteArrayElements(message, NULL);
    const char* msg = reinterpret_cast<char*>(bytes);
    int ciphertext_len = env->GetArrayLength(message);
    
    // Read public key from file
    /*const char* path = env->GetStringUTFChars(publicKeyPath, 0);
    FILE* pubFile = fopen(path, "r");
    RSA* rsa = PEM_read_RSA_PUBKEY(pubFile, NULL, NULL, NULL);
    fclose(pubFile);
    env->ReleaseStringUTFChars(publicKeyPath, path);*/
    const char* nativeStringKey = env->GetStringUTFChars(publicKey, NULL);
     
    //
    BIO* keybio = BIO_new_mem_buf(nativeStringKey, -1);
    RSA* rsa = RSA_new();
    rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, NULL, NULL);

    // Decrypt message with private key
    unsigned char decrypted[2048];
    int len = RSA_public_decrypt(ciphertext_len, (unsigned char*) msg, decrypted, rsa, RSA_PKCS1_PADDING);

    // Create byte array for decrypted message
    jbyteArray result = env->NewByteArray(len);
    env->SetByteArrayRegion(result, 0, len, (jbyte*) decrypted);

    // Clean up
    RSA_free(rsa);
    BIO_free_all(keybio);
    env->ReleaseStringUTFChars(publicKey, nativeStringKey);

    env->ReleaseByteArrayElements(message, bytes, 0);

    return result;
}