package com.mrljdx.jnisecurity;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.mrljdx.security.SecurityUtils;

/**
 * 验证 MD5 和 SHA1 的值参考如下网址：
 * see @link http://encode.chahuo.com/
 */
public class MainActivity extends AppCompatActivity {

    TextView tvMD5;
    TextView tvSHA1;
    EditText etInput;
    Button btnSecurity;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tvMD5 = (TextView) findViewById(R.id.tvMD5);
        tvSHA1 = (TextView) findViewById(R.id.tvSHA1);

        etInput = (EditText) findViewById(R.id.etInput);
        btnSecurity = (Button) findViewById(R.id.btnSecurity);

        btnSecurity.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String inputData = etInput.getText().toString().trim();
                if (TextUtils.isEmpty(inputData)) {
                    Toast.makeText(MainActivity.this, "请输入加密内容", Toast.LENGTH_LONG).show();
                    return;
                }
                tvMD5.setText(inputData + "\nMD5 result is :\n" + SecurityUtils.nativeMD5Str(inputData));
                tvSHA1.setText(inputData + "\nSHA1 reult is :\n" + SecurityUtils.nativeSHAStr(inputData));
            }
        });

    }
}
