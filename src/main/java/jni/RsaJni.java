package jni;

/**
 * jni.MyClass
 *
 * @author yangming
 * @date 2023-05-11 16:20:39
 */
public class RsaJni {
    static {
        if (System.getProperty("os.name").contains("Windows")) {
            System.loadLibrary("RsaJniProject");
        } else {
            System.load("/opt/rsajni/RsaJniProject.so");
        }
    }
    public native byte[] encryptRsaByPublicKey(byte[] message, String publicKey);
    public native byte[] decryptRsaByPrivateKey(byte[] message, String privateKey);

    public native byte[] encryptRsaByPrivateKey(byte[] message, String privateKey);
    public native byte[] decryptRsaByPublicKey(byte[] message, String publicKey);
}
