from setuptools import find_packages
from setuptools import setup

setup(
    name='fra532_slam',
    version='0.0.0',
    packages=find_packages(
        include=('fra532_slam', 'fra532_slam.*')),
)
