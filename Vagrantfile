# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "debian/jessie64"

  config.vm.define "weather"
  config.vm.define "vmc"

  config.vm.provision "ansible" do |ansible|
      ansible.playbook = "provisioning/playbook.yml"
  end
end
