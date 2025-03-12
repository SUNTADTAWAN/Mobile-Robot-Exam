from setuptools import find_packages
from setuptools import setup

setup(
    name='fra532_exam1',
    version='0.0.0',
    packages=find_packages(
        include=('fra532_exam1', 'fra532_exam1.*')),
)
