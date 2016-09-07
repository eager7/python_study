
from setuptools import setup, find_packages

setup(name='Hello',
    version='1.0',
    description='A Simple Example',
    author='PCT',
    py_modules=['hello'],
    packages=find_packages(),
    install_requires=[
        'pyzmq>1.0',
        'pct>1.0',
    ],
)

