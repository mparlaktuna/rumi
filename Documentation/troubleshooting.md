# Troubleshooting during Rumi Development

## Compiling linux
Issue: While compiling linux kernel with the config genereated it fails with following
```No rule to make target 'debian/canonical-certs.pem', needed by 'certs/x509_certificate_list'. Stop.```
According to https://askubuntu.com/questions/1329538/compiling-kernel-5-11-11-and-later clean the CONFIG_SYSTEM_TRUSTED_KEYS and CONFIG_SYSTEM_REVOCATION_KEYS
