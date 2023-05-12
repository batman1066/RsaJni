package org.example;

import jni.RsaJni;

import java.io.UnsupportedEncodingException;

/**
 * org.example.Test
 *
 * @author yangming
 * @date 2023-05-11 18:54:49
 */
public class Test {
    static String pubkey =
            "-----BEGIN PUBLIC KEY-----\n" +
                    "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAiRwPTTNLk+MY2IikYzgm\n" +
                    "G+rdB9hMizh7swPJbi3Hq0ppxMpunbdAdCHHLBK8BRdCqe07B7Zao/y4XBZXO0iV\n" +
                    "75sH9w5sG1BbckErC3AMDP5kA7kQH5ZQTBnh/RkE4T7TjK1YJETy4MiVuLpcuIYw\n" +
                    "nPt9yxppWpQEZL90KxsSTE3Qc9K7Sp4mem2faiwq2fdrNb/8RzMf5UGE5nkzji8z\n" +
                    "mp2SLG6Lod+CJwHu4fLLuagwhfX6R3TWHS2hKuwOj9QYFT+kY+Wowx1waJ7wmOCk\n" +
                    "+P/twwrDrCP/p6yvCgSpV+nYDA+yfzBbDELNmGBrAAKYfLsj3wo4Ud/5bAJLCFfW\n" +
                    "UQIDAQAB\n" +
                    "-----END PUBLIC KEY-----";
    static String priKey =
            "-----BEGIN PRIVATE KEY-----\n" +
                    "MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQCJHA9NM0uT4xjY\n" +
                    "iKRjOCYb6t0H2EyLOHuzA8luLcerSmnEym6dt0B0IccsErwFF0Kp7TsHtlqj/Lhc\n" +
                    "Flc7SJXvmwf3DmwbUFtyQSsLcAwM/mQDuRAfllBMGeH9GQThPtOMrVgkRPLgyJW4\n" +
                    "uly4hjCc+33LGmlalARkv3QrGxJMTdBz0rtKniZ6bZ9qLCrZ92s1v/xHMx/lQYTm\n" +
                    "eTOOLzOanZIsbouh34InAe7h8su5qDCF9fpHdNYdLaEq7A6P1BgVP6Rj5ajDHXBo\n" +
                    "nvCY4KT4/+3DCsOsI/+nrK8KBKlX6dgMD7J/MFsMQs2YYGsAAph8uyPfCjhR3/ls\n" +
                    "AksIV9ZRAgMBAAECggEAMqIEHJRW0rRI1p4PZvyzRhgDrAP6sGcZd1BssJ2DYQRH\n" +
                    "7v56vw+PY9Odg+8fNBoU6j/LTtvOuUR4qLkvWZtCk4uC83+F+MhCHP1n8f9c0+eV\n" +
                    "87IB/Eg8Ov5L8HWu0aer5AWXyT0VHGG2uNNJrnMPvMk6+Sg1w9dpj/ML6WdD6J1B\n" +
                    "OTIrgTp8avLf8VnuR4Ndz1p2FsOcdkaLYIgcMNqFAj1Lep5CI3mGIJkFi8TK9QW/\n" +
                    "i/7bl6hjaoL4Or/UU5GbBZVffS+j5i6XM67gC7etNhyvEmd+PrZZYgDVGDNCK44V\n" +
                    "g3s30ZprGETCYWkV4zPErLLT/8HZds/5cu8N0z3oYQKBgQDHj7jAxDhFLQuqtx61\n" +
                    "GsYgfA5GHBYudsjqryajAfzV6KVrqjEUqOK3g7/9VjIFHmLwcvQh4rkZyIJBSkk6\n" +
                    "PFIIpWvxOUxvXFTnj2wNa9tASmQmuF1f2wwva59FZcZP0541ErIoJEfJ1tT5xCW6\n" +
                    "x5irLjN7JYs9tpkPl++QtSLCvQKBgQCv4tFCsScjJLrMcERG9Q7AoyPJaCDHxyoe\n" +
                    "uKvaeaLUMvMpJ3HGEzPSFUW6k34F8odP7BkvFRV8dBS4Tzw3BZ1zPB6JMDwr/a3C\n" +
                    "LSRgtHsye5qvoekP5EDf8wA+EmqfriNNqNHLzQR8HBC8xJnk/+7N+In6kXNfd8jN\n" +
                    "1JNYCNQFJQKBgQC9A3KRGgjV9HFdc24hSMepkvaODyIvRhDMv7KPqF1KWbz8Ocmc\n" +
                    "8M0z1hTtJUvhL0O0zJxQ0AZT1mcQ4gRzpRhp2gxgAM5Vl5VPcbd9CtAyl4M+bVb7\n" +
                    "aGSlMYE8YMYxa5UoXZnijWJ1WQaFvvOhclU2pV7bX9b/T8ivTU/5tqbC3QKBgHaH\n" +
                    "Tug3xB0t0miVO53p5VAyYJqI/pZDBIKBhuaLVAzWbQGN4GFQbXqk9UGfxayyXTeh\n" +
                    "7vLIrZsaCyCN3RFjSlDu8dEX3WTz5pXVoA8/cUp6+6piXVJlSsbg1of+FzaWvpnG\n" +
                    "K+PAvMX6j9j2UJN/WeoaFLn0LSDn8z2qhMUt5du1AoGAWKUVBUV3VZU2X1PJivVH\n" +
                    "as4yzF35q6yx6TibpLRDidIpxf3X+Bpko5p4Vvo1s11HW3KziY1/0r6BJ2cKanRk\n" +
                    "mH8hjd1y0klwJ42X5od/6FUp1FEba7bMppUKaU7Sf1Dio/TpRPx2Y9QZWixDGAgF\n" +
                    "m+r7dXLoDUbRFeRP18+hE9E=\n" +
                    "-----END PRIVATE KEY-----";

    public static void main(String[] args) throws UnsupportedEncodingException {
        String message = "abcdefg123456";
        RsaJni rsaJni = new RsaJni();
        long startTime = System.currentTimeMillis();
        for(int i=0;i<1;i++) {
            try {
                // Encrypt message with public key
                byte[] encrypted = rsaJni.encryptRsaByPrivateKey(message.getBytes(),priKey );
                // Decrypt message with private key
                byte[] decrypted = rsaJni.decryptRsaByPublicKey(encrypted, pubkey);
                System.out.println(new String(decrypted));
            }catch (Throwable e){
                e.printStackTrace();
                continue;
            }
        }
        long endTime = System.currentTimeMillis();
        System.out.println("BC加密耗时:{}ms"+ (endTime - startTime));
    }
}
