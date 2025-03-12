from setuptools import find_packages
from setuptools import setup

setup(
    name='fra532_gazebo',
    version='0.0.0',
    packages=find_packages(
        include=('fra532_gazebo', 'fra532_gazebo.*')),
)
