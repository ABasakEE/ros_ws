from setuptools import find_packages, setup

package_name = 'py_srvcli'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='arjoe',
    maintainer_email='arjoe.basak@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        	'server=py_srvcli.service:main',
        	'client=py_srvcli.client:main',
        	'publisher=py_srvcli.publisher:main',
        	'subscriber=py_srvcli.subscriber:main',
        	'server3=py_srvcli.server_three:main',
        	'client3=py_srvcli.client_three:main',
        	'aruco_service=py_srvcli.aruco_service:main',
        	'aruco_client=py_srvcli.aruco_client:main',
        	
        ],
    },
)
