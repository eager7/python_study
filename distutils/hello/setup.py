from distutils.core import setup

setup(name='Hello',
    version='1.0',
    description='A Simple Example',
    author='PCT',
    py_modules=['hello']
)
setup(install_requires=["numpy >= 3.8.1", "pandas >= 0.14.1"])

