from setuptools import find_packages
from setuptools import setup

setup(
    name='mir_msgs',
    version='1.1.1',
    packages=find_packages(
        include=('mir_msgs', 'mir_msgs.*')),
)
